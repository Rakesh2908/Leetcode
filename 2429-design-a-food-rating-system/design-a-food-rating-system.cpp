class FoodRatings {
    map<string, pair<string, int>> mp1;
    map<string, map<int, set<string>>> mp2;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            mp1[foods[i]] = {cuisines[i], ratings[i]};
            mp2[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        auto foodInfo = mp1.find(food);
        string cuisine = foodInfo->second.first;
        int oldRating = foodInfo->second.second;
        foodInfo->second.second = newRating;

        mp2[cuisine][oldRating].erase(food);
        if (mp2[cuisine][oldRating].empty())
            mp2[cuisine].erase(oldRating);

        mp2[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        return *mp2[cuisine].rbegin()->second.begin();
    }
};