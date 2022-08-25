class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        uint32_t count = 0;
        while(count<32)
        {
            rev = rev << 1;
            if(n&1 == 1) rev++;
            n = n >> 1;
            count++;
        }

        return rev;
    }
};