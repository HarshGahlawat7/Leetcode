class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());
        
        // Use long long to prevent integer overflow during mass accumulation
        long long currentMass = mass;
        
        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) {
                currentMass += asteroid; // Absorb the asteroid's mass
            } else {
                return false; // Planet is destroyed
            }
        }
        
        return true;
    }
};