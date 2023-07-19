class Solution {
public:
    int brokenCalc(int X, int Y) {
        int operations = 0;

        while (Y > X) {
            // If Y is greater than X, we have two options:
            // 1. If Y is odd, we have to perform a decrement operation to make it even.
            // 2. If Y is even, we can just perform a double operation.
            // We always choose the operation that reduces Y to the nearest even number
            // since using double will reduce the difference between X and Y faster.
            if (Y % 2 == 1) {
                Y++; // Increment Y to make it even.
                operations++; // Perform the decrement operation.
            }

            Y /= 2; // Perform the double operation.
            operations++; // Increment the number of operations performed.
        }

        // At this point, Y is not greater than X, so we just need to perform X - Y decrement operations
        // to reach the target value X from Y.
        return operations + (X - Y);
    }
};
