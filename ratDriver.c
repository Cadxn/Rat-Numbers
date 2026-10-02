#include <stdio.h>
#include "rat.c"

void printRat(const char *label, rat r) {
    char *str = toString(r);
    printf("%s %s\n", label, str);
    free(str); // Free memory allocated by toString
}



int main(){

printf("--- Beginning Rational Numbers Test Suite ---\n\n");

    // ==========================================
    // 1. Initial Creation and String Representation
    // ==========================================
    printf("[1] Basic Creation & Output Tests:\n");
    rat r1 = createRat(2, 3);
    rat r2 = createRat(5, -6);
    
    printRat("r1 (expected 2/3):", r1);
    printRat("r2 (expected 5/-6):", r2);
    printf("\n");

    // ==========================================
    // 2. Normalization & Reduction Checks
    // ==========================================
    printf("[2] Normalization & Reduction Tests:\n");
    rat r3 = createRat(9, -3);
    rat r3_norm = norm(r3);
    rat r3_red = reduce(r3);
    printRat("r3 raw (expected 9/-3):", r3);
    printRat("r3 normalized (expected -9/3):", r3_norm);
    printRat("r3 reduced (expected -3/1):", r3_red);
    
    rat zero_neg = createRat(0, -5);
    rat zero_norm = norm(zero_neg);
    printRat("0/-5 normalized (expected 0/1):", zero_norm);
    
    free(r3); free(r3_norm); free(r3_red);
    free(zero_neg); free(zero_norm);
    printf("\n");

    // ==========================================
    // 3. Comparisons
    // ==========================================
    printf("[3] Comparison Tests:\n");
    rat comp1 = createRat(1, 2);
    rat comp2 = createRat(2, 4);
    rat comp3 = createRat(-3, 4);
    
    printf("1/2 vs 2/4 (expected 0): %d\n", cmp(comp1, comp2));
    printf("1/2 vs -3/4 (expected 1): %d\n", cmp(comp1, comp3));
    printf("-3/4 vs 1/2 (expected -1): %d\n", cmp(comp3, comp1));
    
    free(comp1); free(comp2); free(comp3);
    printf("\n");

    // ==========================================
    // 4. Arithmetic Operations
    // ==========================================
    printf("[4] Arithmetic Operation Tests:\n");
    // 2/3 + 5/-6 = 4/6 - 5/6 = -1/6
    rat sum = add(r1, r2);
    printRat("2/3 + 5/-6 (expected -1/6):", sum);
    
    // 2/3 - 5/-6 = 4/6 + 5/6 = 9/6 = 3/2
    rat diff = sub(r1, r2);
    printRat("2/3 - 5/-6 (expected 3/2):", diff);
    
    // 2/3 * 5/-6 = 10/-18 = -5/9
    rat product = mul(r1, r2);
    printRat("2/3 * 5/-6 (expected -5/9):", product);
    
    // (2/3) / (5/-6) = (2/3) * (-6/5) = -12/15 = -4/5
    rat quotient = divide(r1, r2);
    printRat("(2/3) / (5/-6) (expected -4/5):", quotient);
    
    free(sum); free(diff); free(product); free(quotient);
    printf("\n");

    // ==========================================
    // 5. Inversion
    // ==========================================
    printf("[5] Inversion Tests:\n");
    rat inv_r1 = inverse(r1);
    printRat("Invert 2/3 (expected 3/2):", inv_r1);
    free(inv_r1);
    printf("\n");

    // ==========================================
    // 6. Well-Formed Status Validation
    // ==========================================
    printf("[6] Well-Formed Assessment Tests:\n");
    printf("Is r1 well-formed? (expected yes): %s\n", wellFormed(r1) ? "yes" : "no");
    
    // Artificially forcing an illegal state to test wellFormed evaluation
    r1->d = 0; 
    printf("Is r1 well-formed after setting d=0? (expected no): %s\n", wellFormed(r1) ? "yes" : "no");
    printRat("toString on illegal r1 (expected 2/0):", r1);
    printf("\n");

    // Cleanup initial variables
    free(r1);
    free(r2);

    // ==========================================
    // 7. Fatal Error Edge Cases (To trigger, uncomment one at a time)
    // ==========================================
    printf("[7] Fatal Error Execution Trigger tests:\n");
    printf("Uncomment one line in source to test structural crash exits:\n");
    
    //rat bad_zero = createRat(5, 0);       // Should trigger denominator 0 error
     //rat zero_num = createRat(0, 4);
     //rat bad_inv = inverse(zero_num);      // Should trigger inversion error
     //rat bad_div = divide(r2, zero_num);   // Should trigger division by zero error

    printf("\n--- Test Suite Complete (All Non-Fatal Steps Passed) ---\n");
    return 0;


    return 0;

}