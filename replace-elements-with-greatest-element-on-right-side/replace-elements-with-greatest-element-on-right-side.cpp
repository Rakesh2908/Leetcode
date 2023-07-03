class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(); // Get the size of the input vector
        int temp, maxi = -1; // Initialize variables 'temp' and 'maxi'

        for (int i = n - 1; i >= 0; i--) {
            temp = arr[i]; // Store the current element

            arr[i] = maxi; // Replace the current element with the maximum element on the right side
            maxi = max(maxi, temp); // Update the maximum element on the right side if necessary
        }

        return arr; // Return the modified array
    }
};
