/*
https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2024-05-03

165. Compare Version Numbers
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.


Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".
Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.


Constraints:

1 <= version1.length, version2.length <= 500
version1 and version2 only contain digits and '.'.
version1 and version2 are valid version numbers.
All the given revisions in version1 and version2 can be stored in a 32-bit integer.

*/

class Solution
{
public:
    // Use Testcase
    // version1 =
    // "1.2"
    // version2 =
    // "1.10"

    // version1 =
    // "1.1"
    // version2 =
    // "1.10"
    // op = -1

    // Output -1

    int compareVersion(string ver1, string ver2)
    {
        int i = 0, j = 0, m = ver1.length(), n = ver2.length();

        while (i < m || j < n)
        { // note here is || not && becuase version1 = "1.01" version2 = "1.001", op = 0 dry run
            int revision1 = 0;
            while (i < m && ver1[i] != '.')
            {
                revision1 = revision1 * 10 + (ver1[i] - '0');
                i++;
            }

            int revision2 = 0;
            while (j < n && ver2[j] != '.')
            {
                revision2 = revision2 * 10 + (ver2[j] - '0');
                j++;
            }

            if (revision1 == revision2)
            {
                i++;
                j++;
            }
            else if (revision1 > revision2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
};

// && version code
// class Solution {
// public:
//     int compareVersion(string a, string b)
//     {
//         int n=a.length(), m=b.length(), i=0, j=0;
//         while(i<n && j<m)
//         {
//             long long int p=0, q=0;
//             while(i<n && a[i]!='.')
//             {
//                 p=(p*10)+a[i]-'0';
//                 i++;
//             }
//             while(j<m && b[j]!='.')
//             {
//                 q=(q*10)+b[j]-'0';
//                 j++;
//             }
//             if(p>q)
//                 return 1;
//             else if(q>p)
//                 return -1;
//             i++;
//             j++;
//         }

//         while(i<n)
//         {
//             long long int p=0;
//             while(i<n && a[i]!='.')
//             {
//                 p= (p*10)+ (a[i]-'0');
//                 i++;
//             }
//             if(p>0)
//                 return 1;
//             i++;
//         }
//         while(j<m)
//         {
//             long long int p=0;
//             while(j<m && b[j]!='.')
//             {
//                 p= (p*10)+ (b[j]-'0');
//                 j++;
//             }
//             if(p>0)
//                 return -1;
//             j++;
//         }
//         return 0;
//     }
// };