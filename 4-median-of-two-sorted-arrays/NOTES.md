[Striver](https://www.youtube.com/watch?v=NTop3VTjmxk)
​
n1 = size of array 1
n2 = size of array 2
calculate partition point for array
lo = 0
hi = n1
cut1 = (lo + hi) // 2;
​
when you calculate the median you divide the array into two segments of equal length
so we pick cut1 elements from array 1 and (n1 + n2 + 1) / 2 - cut1 elements from array 2
we use the +1 to account for cases when (n1 + n2) is odd.
​
Then we check the element to the left of cut1 is less than element to the right of cut2 and
the element to the left of the cut2 is less than element to the right of cut 2.
​
if the above conditions aren't satisfied lo and high are moved according to the condition to change the position of cut1 and cut2
​
nums1 = [7,12,14,15]
nums2 = [1,2,3,4,9,11]
​
cut1 = 1
cut2 = 4
​
7         | 12 14 15
1 2 3 4| 9 11
​
the median will be (max(left1,left2) + min(right1,right2)) / 2.0 if its even no of elements
max(left1,left2) / 2 if its odd no of elements.
​
special case if n1 > n2 swap the arrays becuase it will result in index out of bounds error in while calcuatiting cut2.
​
​
​
​
​