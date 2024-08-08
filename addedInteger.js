/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var addedInteger = function(nums1, nums2) {
    return Math.min.apply(null, nums2)-Math.min.apply(null, nums1);
};

var nums1 = [2,6,4], nums2 = [9,7,5];
console.log(addedInteger(nums1, nums2));