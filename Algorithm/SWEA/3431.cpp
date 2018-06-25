//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWE_ZXcqAAMDFAV2&categoryId=AWE_ZXcqAAMDFAV2&categoryType=CODE

scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int l, u, x;
        scanf("%d %d %d", &l, &u, &x);
        if(x < l) {
            printf("#%d %d\n", test_case, l - x);
        }else if(x > u){
            printf("#%d %d\n", test_case, -1);
        }else {
            printf("#%d %d\n", test_case, 0);
        }
    }