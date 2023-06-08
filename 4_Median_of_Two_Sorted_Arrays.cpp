#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchIndex(vector <int> & nums1, vector <int> & nums2, int find) {
    int ret = -1;

    int n = nums1.size();
    int m = nums2.size();

    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high)/2;

        int hold = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();

        if (hold != nums2.size() && nums2[hold] == nums1[mid]) {
            int counter = hold;
            while (counter < m && nums2[counter] == nums1[mid]) {
                if (counter + mid + 1 == find) {
                    return mid;
                } 
                counter++;
            }
        }  


        if (mid + hold == find) {
            ret = mid;
            break;
        } else if (mid + hold > find) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ret;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n == 0) {
        if (m % 2) {
            return nums2[(m - 1)/2];
        } else {
            return (nums2[(m - 1)/2] + nums2[(m - 1)/2 + 1])/2.0;
        }
    } else if (m == 0) {
        if (n % 2) {
            return nums1[(n - 1)/2];
        } else {
            return (nums1[(n - 1)/2] + nums1[(n - 1)/2 + 1])/2.0;
        }
    }

    if (nums1[n - 1] <= nums2[0]) {
        if (n > m) {
            if ((n + m) % 2) {
                return nums1[(n + m - 1)/2];
            } else {
                return (nums1[(n + m - 1)/2] + nums1[(n + m - 1)/2 + 1])/2.0;
            }
        } else if (m > n) {
            if ((n + m) % 2) {
                return nums2[(n + m - 1)/2 - n];
            } else {
                return (nums2[(n + m - 1)/2 - n] + nums2[(n + m - 1)/2 - n + 1])/2.0;
            }
        } else {
            return (nums1[n - 1] + nums2[0])/2.0;
        }
    } else if (nums2[m - 1] <= nums1[0]) {
        if (n > m) {
            if ((n + m) % 2) {
                return nums1[(n + m - 1)/2 - m];
            } else {
                return (nums1[(n + m - 1)/2 - m] + nums1[(n + m - 1)/2 - m + 1])/2.0;
            }
        } else if (m > n) {
            if ((n + m) % 2) {
                return nums2[(n + m - 1)/2];    
            } else {
                return (nums2[(n + m - 1)/2] + nums2[(n + m - 1)/2 + 1])/2.0;    
            }
        } else {
            return (nums2[m - 1] + nums1[0])/2.0;
        }
    }


    if ((n + m) % 2) {
        int first = searchIndex(nums1, nums2, (n + m - 1)/2);
        if (first != -1) {
            return nums1[first];
        }


        int second = searchIndex(nums2, nums1, (n + m - 1)/2);
        return nums2[second];
    } else {
        int firstNum;
        int first = searchIndex(nums1, nums2, (n + m - 1)/2);
        if (first == -1) {
            first = searchIndex(nums2, nums1, (n + m - 1)/2);
            firstNum = nums2[first];
        } else {
            firstNum = nums1[first];
        }

        int secondNum;
        int second = searchIndex(nums1, nums2, ((n + m - 1)/2) + 1);

        if (second == -1) {
            second = searchIndex(nums2, nums1, ((n + m - 1)/2) + 1);
            secondNum = nums2[second];
        } else {
            secondNum = nums1[second];
        }

        return (firstNum + secondNum)/2.0;
    }

}

int main() {
    return 0;
}