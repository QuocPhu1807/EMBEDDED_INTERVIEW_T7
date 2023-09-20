#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void check_index_0_FirstTime (char money[]) {
    switch (money[0])
    {
    case '0':
        break;
    case '1':
        printf("Mot ");
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        printf("Bon ");
        break;
    case '5':
        printf("Nam ");
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    default:
        break;
    }
    if(money[0] != '0') printf("Tram ");
}

void check_index_1_FirstTime (char money[]) {
    switch (money[1])
    {
    case '0':
        if (money[0] != '0' && money[2] != '0') printf("Le ");
        break;
    case '1':
        printf("Muoi "); // "Mười"
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        printf("Bon ");
        break;
    case '5':
        printf("Nam "); // "Năm"
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    default:
        break;
    }
    if(money[1] != '0' && money[1] != '1') printf("Muoi ");
}


////////////////////////////////////////////////////////////////////////////////////////////////
void check_index_0 (char money[]) {

    switch (money[0])
    {
    case '0':
        printf("Khong ");
        if (money[1] != '0' || money[2] != '0') printf("tram ");
        break;
    case '1':

        printf("Mot "); // "Một"
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        printf("Bon ");
        break;
    case '5':
        printf("Nam "); // "Năm"
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    default:
        break;
    }
    if(money[0] != '0') printf("Tram ");
}

void check_index_1 (char money[]) {
    switch (money[1])
    {
    case '0':
        if (money[2] != '0') printf("Le ");
        break;
    case '1':
        printf("Muoi "); // "Mười"
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        printf("Bon ");
        break;
    case '5':
        printf("Nam "); // "Năm"
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    default:
        break;
    }
    if(money[1] != '0' && money[1] != '1') printf("Muoi ");
}

void check_index_2 (char money[]) {
    switch (money[2])
    {
    case '0':
        break;
    case '1':
        if(money[1] != '0' && money[1] != '1') printf("Mot "); // "Mốt"
        else printf("Mot "); // "Một"
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        printf("Bon ");
        break;
    case '5':
        if(money[1] != '0') printf("Lam "); // "Lăm "
        else printf("Nam ");
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    default:
        break;
    }
}

void prin (char money[]) {
    
    static uint8_t firt_Uinit = 0;
    // VD: 10 112 325 nó sẽ đọc 10 ở phần if() và lúc này money của nó là "010"
    //                      đọc 112 và 325 ở else()
    // VD: 1 112 325 nó sẽ đọc 1 ở phần if() và lúc này money của nó là "001"
    //                      đọc 112 và 325 ở else()
    if (firt_Uinit == 0) {
        for (uint8_t i = 0; i < 3; i++) {
            if (i == 0) check_index_0_FirstTime(money);
            else if (i == 1) check_index_1_FirstTime(money);
            else check_index_2(money);
        }
        firt_Uinit = 1;
    }
    else {
        for (uint8_t i = 0; i < 3; i++) {
            if (i == 0) check_index_0(money);
            else if (i == 1) check_index_1(money);
            else check_index_2(money);
        }
    }
}


///////////////////////////////////////////////////////////////////////
uint8_t sizeStr (char str[]) {

    uint8_t size = 0;
    char *ptr = str;
    while(*ptr != '\0') {
        size++;
        ptr++;
    }
    return size;
}


int main () {
    
    // nhập trực tiếp vào str
    char str[] = "2000000000025000005";

    uint8_t size = sizeStr(str);
    
    // tạo 1 chuỗi chứa 3 số ở cùng 1 hàng (tỷ, triệu, ...)
    char money_Unit[3];

    // nếu ở hàng tỷ có 1 chứ số
    // VD: 1 000 000 000 thì nó sẽ thêm 00 vào đầu vào chuỗi => "001"
    uint8_t i = 0;
    uint8_t i_Unit = 0;
    uint8_t checkZero = size % 3;
    if (checkZero == 1) {
        money_Unit[i_Unit] = '0';
        i_Unit++;
        money_Unit[i_Unit] = '0';
        i_Unit++;
    }
    // nếu ở hàng tỷ có 2 chữ số thì thêm 1 số 0 => "0xx"
    else if (checkZero == 2) {
        money_Unit[i_Unit] = '0';
        i_Unit++;
    }
    // index_Unit để tính toán và lưu vị trí của hàng đơn vị trong chuỗi chính của chúng ta
    // để nhận biết và in ra "Ty ", "Trieu ", "Nghin"
    uint8_t index_Unit = size;

    while(i < size) {
        money_Unit[i_Unit] = str[i];
        i++;
        i_Unit++;

        if (i_Unit == 3) {

            // vào hàm in và in chữ số tương ứng
            prin(money_Unit);
            i_Unit = 0;

            uint8_t j = i;
            uint8_t checkZero = 0;

            // (index_Unit - 1) / 3  là vị trí của "Tỷ ", "Triệu", "Nghìn "
            // duyệt từ hàng lớn nhất
            // 1 -> 3 tương ứng nghìn, triệu, tỷ
            // 4 -> 6 tương ứng nghìn tỷ, triệu tỷ, tỷ tỷ
            // 7 -> 9 có thểm thêm nếu muốn
            switch ((index_Unit - 1) / 3) {
            case 0:
                break;
            case 1:
                j = i;
                printf("Nghin ");
                // check zero và giảm index_Unit đi 3 để đi sang hàng tiếp theo
                while (str[j] != '\0') {
                    if (str[j] != '0') {
                        index_Unit = index_Unit - 3;
                        checkZero++;
                        break;
                    }
                    j++;
                }
                // kiểm tra nếu các kí tự tiếp theo bằng 0 thì kết thúc chương trình
                if (checkZero == 0) return 0;
                break;
            case 2:
                j = i;
                printf("Trieu ");
                while (str[j] != '\0') {
                    if (str[j] != '0') {
                        index_Unit = index_Unit - 3;
                        checkZero++;
                        break;
                    }
                    j++;
                }
                if (checkZero == 0) return 0;
                break;
            case 3:
                j = i;
                printf("Ty ");
                while (str[j] != '\0') {
                    if (str[j] != '0') {
                        index_Unit = index_Unit - 3;
                        checkZero++;
                        break;
                    }
                    j++;
                }
                if (checkZero == 0) return 0;
                break;
            break;
            case 4:
                j = i;
                printf("Nghin ");
                while (str[j] != '\0') {
                    if (str[j] != '0') {
                        index_Unit = index_Unit - 3;

                        if (str[size - 10] == '0' && str[size - 11] == '0' && str[size - 12] == '0') {
                            printf("Ty ");
                            // dời sang hàng triệu
                            index_Unit = index_Unit - 3;
                            i = i + 3;
                        }
                        
                        checkZero++;
                        break;
                    }
                    j++;
                }
                if (checkZero == 0) {
                    if ((index_Unit - 1) / 3 == 4) {
                        printf("Ty ");
                        return 0;
                    }
                }
                break;
            case 5:
                j = i;
                printf("Trieu ");
                index_Unit = index_Unit - 3;
                checkZero++;
                break;
            case 6:
                j = i;
                printf("Ty ");
                index_Unit = index_Unit - 3;
                checkZero++;
                break;
            default:
                break;
           }
            
        }
    }
    return 0;
}
