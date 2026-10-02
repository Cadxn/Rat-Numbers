#include <stdio.h>
#include "rat.c"

void runTest(const char* testName, rat result, const char* expectedStr) {
    char *resultStr = toString(result);
    printf("[%s] Expected: %s | Got: %s\n", testName, expectedStr, resultStr);
    
    // Clean up memory to avoid leaks during testing
    free(resultStr);
    free(result);
}


int main(){

    printf("=== STARTING RATIONAL NUMBER TEST SUITE ===\n\n");

    // 1. Basic Setup & Math Operations
    rat r1 = createRat(2, 3);   //  2/3
    rat r2 = createRat(5, -6);  // -5/6
    
    // Test Addition: 2/3 + (-5/6) = 4/6 - 5/6 = -1/6
    runTest("Addition (Standard)", add(r1, r2), "-1/6");
    
    // Test Subtraction: 2/3 - (-5/6) = 4/6 + 5/6 = 9/6 = 3/2
    runTest("Subtraction (Standard)", sub(r1, r2), "3/2");
    
    // Test Multiplication: (2/3) * (-5/6) = -10/18 = -5/9
    runTest("Multiplication (Standard)", mul(r1, r2), "-5/9");
    
    // Test Division: (2/3) / (-5/6) = (2/3) * (-6/5) = -12/15 = -4/5
    runTest("Division (Standard)", divide(r1, r2), "-4/5");

    printf("\n=== TESTING EDGE CASES ===\n\n");

    // 2. Complex/Large Reductions
    rat rLarge1 = createRat(100, 200); // 1/2
    rat rLarge2 = createRat(15, 45);   // 1/3
    runTest("Large Reduction Add", add(rLarge1, rLarge2), "5/6");
    
    // 3. Multiplication and operations with Zero
    rat rZero = createRat(0, 5); // 0/1
    rat rSimple = createRat(3, 4);
    runTest("Multiply by Zero", mul(rSimple, rZero), "0/1");
    runTest("Add with Zero", add(rSimple, rZero), "3/4");

    // 4. Testing Comparisons (cmp)
    printf("\n=== TESTING COMPARISONS ===\n");
    rat c1 = createRat(1, 2);
    rat c2 = createRat(2, 4);
    rat c3 = createRat(3, 4);
    
    printf("[cmp] 1/2 vs 2/4 (Expected 0): %d\n", cmp(c1, c2));
    printf("[cmp] 1/2 vs 3/4 (Expected -1): %d\n", cmp(c1, c3));
    printf("[cmp] 3/4 vs 1/2 (Expected 1): %d\n", cmp(c3, c1));

    // 5. Testing Legal Form (wellFormed)
    printf("\n=== TESTING WELL-FORMED STATE ===\n");
    printf("Is r1 well formed initially? (Expected yes): %s\n", wellFormed(r1) ? "yes" : "no");
    
    // Force r1 into an ill-formed state by corrupting the denominator
    r1->d = 0;
    printf("Is r1 well formed after setting d=0? (Expected no): %s\n", wellFormed(r1) ? "yes" : "no");

    // Clean up initial test objects
    free(r2);
    free(rLarge1);
    free(rLarge2);
    free(rZero);
    free(rSimple);
    free(c1);
    free(c2);
    free(c3);
    // Note: We don't free(r1) here because its denominator is 0, 
    // but in normal behavior you would track your allocations cleanly.

    printf("\n=== TESTING COMPLETE ===\n");
    return 0;

}