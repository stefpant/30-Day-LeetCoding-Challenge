class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int counter = 0;
        for( char c : S ){//save in S only valid chars, then resize
            if( c == '#'){ if(counter) counter--; }
            else S[counter++] = c;
        }
        S.resize(counter);
        counter = 0;
        for( char c : T ){//save in T only valid chars, then resize
            if( c == '#'){ if(counter) counter--; }
            else T[counter++] = c;
        }
        T.resize(counter);
        if( S == T) return true;//compare S, T
        return false;
    }
};
