# download "s3.txt" from http://cs.uef.fi/sipu/datasets/
# wget http://cs.uef.fi/sipu/datasets/s3.txt

"""
given a set of points
1. select k points (centroids) randomly

2. repeat
 - label points
 - update centroids
"""
from pprint import pprint
from typing import Tuple, Sequence, Mapping, Callable, Iterable
import matplotlib.pyplot as plt
from random import sample
from collections import defaultdict
from functools import partial
from statistics import mean

Point = Tuple[float, float]
Centroid = Point
Cluster = Sequence[Point]
Dist_func = Callable[[Point, Point], float]
Distortion = float


def guess_centroids(dataset: Sequence[Point], k: int) -> Sequence[Centroid]:
    return sample(dataset, k=k)


def distance(p: Point, q: Point, /) -> float:
    return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])
    # return sum((xp-xq)*(xp-xq) for xp,xq in zip(p,q))


def label(
    dataset: Sequence[Point], centroids: Sequence[Centroid], dist: Dist_func
) -> Mapping[Centroid, Cluster]:
    d = defaultdict(list)
    for p in dataset:
        pdist = partial(dist, p)
        centroid = min(centroids, key=pdist)
        d[centroid].append(p)
    return d


def update_centroids(clusters: Iterable[Cluster]) -> Sequence[Centroid]:
    centroids = []
    for cluster in clusters:
        xc, yc = list(zip(*cluster))
        centroids.append((mean(xc), mean(yc)))
    return centroids


def distortion(
    labeled_dataset: Mapping[Centroid, Cluster], distance: Dist_func
) -> float:
    dist = 0.0
    for centroid, cluster in labeled_dataset.items():
        pdist = partial(distance, centroid)
        dist += mean(map(pdist, cluster))
    return dist


def _kmeans(
    dataset: Sequence[Point], k: int, n_iter: int, dist: Dist_func
) -> Tuple[Mapping[Centroid, Cluster], Distortion]:
    centroids = guess_centroids(dataset, k)
    for _ in range(n_iter):
        labeled = label(dataset, centroids, dist)
        centroids = update_centroids(labeled.values())
    labeled = label(dataset, centroids, dist)
    return labeled, distortion(labeled, dist)


def kmeans(dataset, k, inner, outer, dist):
    best_distortion = float("inf")
    best_mapping = {}
    for _ in range(outer):
        mapping, distortion = _kmeans(dataset, k, inner, dist)
        if distortion < best_distortion:
            best_mapping = mapping
            best_distortion = distortion
    return best_mapping, best_distortion


if __name__ == "__main__":

    points: Sequence[Point]

    with open("s3.txt") as f:
        points = [tuple(map(float, line.split())) for line in f]

    # pprint(points, width=40)
    X, Y = list(zip(*points))

    d, _ = kmeans(points, k=15, inner=10, outer=15, dist=distance)

    centroids = d.keys()

    Xc, Yc = list(zip(*centroids))

    plt.scatter(X, Y, s=0.5)
    plt.scatter(Xc, Yc)

    plt.show()
