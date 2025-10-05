class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, double>> car(pos.size());
        for(int i = 0; i < pos.size(); i++){
            double time = double(tar - pos[i]) / speed[i];
            car[i] = {pos[i], time};
        }    

        // Sort by starting position descending (closest to target first)
        sort(car.rbegin(), car.rend());

        int fleet = 0;
        stack<double> st;

        for(int i = 0; i < car.size(); i++){
            // Only form a new fleet if the current car's time is greater than top of stack
            if(st.empty() || car[i].second > st.top()){
                fleet++;
                st.push(car[i].second); // push only for new fleet
            }
            // else: car joins existing fleet → do not push
        }

        return fleet;
    }
};
