#include <stdio.h>

unsigned int getSieveOfEratosthenes(int n, int *L)
{
    int A[1000];

    for (unsigned int p = 2; p <= n; p++)
        A[p] = p;
    // for (unsigned int p = 2; p <= n; p++)
    //     printf(" %d ", A[p]);

    for (unsigned int p = 2; p * p <= n; p++)
    {
        if (A[p] != 0)
        {
            unsigned int j = p * p;
            while (j <= n)
            {
                A[j] = 0;
                j = j + p;
            }
        }
    }

    // printf("\n DEBUG 1 %d \n", *count);
    unsigned int count = 0;
    unsigned int i = 0;
    for (unsigned int p = 2; p <= n; p++)
    {
        // printf("\n DEBUG 2 %d \n", *count);
        if (A[p] != 0)
        {
            // printf("\n DEBUG 3 %d \n", *count);
            L[i++] = A[p];
            count++;
        }
    }
    // printf("\n DEBUG 4 %d \n", *count);
    // for (unsigned int p = 2; p <= n; p++)
    //     printf(" %d ", L[p]);
    return count;
}

int main()
{
    int range;
    scanf(" %d", &range);

    int L[1000];

    unsigned int count = getSieveOfEratosthenes(range, L);

    printf(" The Sieve generated is:");
    for (unsigned int i = 0; i < count; i++)
        printf(" %d", L[i]);

    return 0;
}

// // Samplie IO
// 1000
//  The Sieve generated is: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541 547 557 563 569 571 577 587 593 599 601 607 613
// 617 619 631 641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751 757 761 769 773 787 797 809 811 821 823 827 829 839 853 857 859 863 877 881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997 1000