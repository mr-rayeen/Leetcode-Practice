class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        
        //  Yaha dono array ko sort kar diya fir uska diff nikala each index par
        //  fir moves me add karte gaye har move ka absolute nikal kar
        int moves = 0;

        for(int i = 0; i<seats.size(); i++){
            int move = seats[i] - students[i];
            moves += abs(move);
        }

        return moves;
    }
};