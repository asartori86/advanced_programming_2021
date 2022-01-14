
! sum up absolute of "num" integers in array "inp", store result in "asum" 
subroutine sum_abs(inp, num, asum)
  implicit none
  integer, intent(in) :: inp(*), num
  integer, intent(out) :: asum
  integer :: i,s

   s = 0
   do i=1,num
     s = s + abs(inp(i)); 
   end do
   asum = s;
end subroutine sum_abs
 
