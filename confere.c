int solved() {
    int cubo[6][3][3], f, l, c;

    for (f = 0; f < 6; f++) {
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                if (cubo[f][l][c] != cubo[f][0][0])
                    return 0;
            }
        }
    }

    return 1;
}
