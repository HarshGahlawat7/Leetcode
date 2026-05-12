class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        std::sort(tasks.begin(), tasks.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int initial_energy = 0;
        int current_energy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If our current energy is less than the minimum required to start,
            // we must increase our initial energy pool by the difference.
            if (current_energy < minimum) {
                initial_energy += (minimum - current_energy);
                current_energy = minimum;
            }
            
            // Spend the energy required for the task.
            current_energy -= actual;
        }

        return initial_energy;
    }
};