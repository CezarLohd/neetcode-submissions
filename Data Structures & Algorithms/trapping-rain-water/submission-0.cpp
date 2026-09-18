class Solution {
public:
    int trap(vector<int>& height) {
        // nie mozna patrzec na cala plansze naraz
        // trzeba patrzec na 1 pole naraz
        // jak? 
        // dla każdego pola będzie w nim tyle wody:
        // min(lewa[i], prawa[i]) - height[i], 
        // gdzie lewa to tablica z najwiekszymi słupkami od lewej strony
        //
        // czyli jak mamy [0,2,0,3,1,0,1,3,2,1]
        //      to lewa = [0,2,2,3,3,3,3,3,3,3]  i analogicznie
        //     prawa to = [3,3,3,3,3,3,3,3,2,1]
        //
        // i wiedzac to poprostu iterujemy przez calosc
        // sprawdzajac dla kazdego pojedynczego tamten wzor
        // i dodajac wszystko do siebie

        int hsize = height.size();

        vector<int> left(hsize, 0);
        vector<int> right(hsize, 0);

        left[0] = height[0];
        right[hsize - 1] = height[hsize - 1];

        for (int i = 1; i < hsize; ++i) {
            if (height[i] > left[i - 1]) 
                left[i] = height[i];
            else 
                left[i] = left[i - 1];

            if (height[hsize - 1 - i] > right[hsize - i]) 
                right[hsize - 1 - i] = height[hsize - 1 - i];
            else 
                right[hsize - 1 - i] = right[hsize - i];
        }

        // for (int i : left) cout << i << ", ";
        // cout << endl << "chujjj";
        // for (int i : right) cout << i << ", ";

        int solution = 0;

        for (int i = 0; i < hsize - 1; ++i) 
            solution += min(left[i], right[i]) - height[i];
        
        return solution;
    }
};