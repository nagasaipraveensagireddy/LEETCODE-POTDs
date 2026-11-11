class Solution {
public:
    long long calculateCost(long long needA, int costA,
                            long long needB, int costB,
                            int costBoth) {

        int priceA = min(costA, costBoth);
        int priceB = min(costB, costBoth - priceA);

        return needA * priceA + needB * priceB;
    }

    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long option1 = calculateCost(
            need1, cost1, need2, cost2, costBoth
        );

        long long option2 = calculateCost(
            need2, cost2, need1, cost1, costBoth
        );

        return max(option1, option2);
    }
};