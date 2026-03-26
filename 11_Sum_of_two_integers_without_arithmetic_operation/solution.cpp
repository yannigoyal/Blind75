/*
  How it works
  a ^ b → gives sum without carry
  a & b → gives carry bits
  (a & b) << 1 → shifts carry to correct position
  
  Loop logic

  Repeat until no carry remains (b == 0):

  Calculate carry
  Update sum (a = a ^ b)
  Move carry into b
  
  When b = 0, no carry is left → a is the final sum ✅
*/

int getSum(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1; // carry
        a = a ^ b;                // sum without carry
        b = carry;               // move carry
    }
    return a;
}
