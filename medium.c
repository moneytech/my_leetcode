// 338. Counting Bits
int count_byte[] = {/*0*/0,
/*1*/1,
/*2*/1,
/*3*/2,
/*4*/1,
/*5*/2,
/*6*/2,
/*7*/3,
/*8*/1,
/*9*/2,
/*10*/2,
/*11*/3,
/*12*/2,
/*13*/3,
/*14*/3,
/*15*/4,
/*16*/1,
/*17*/2,
/*18*/2,
/*19*/3,
/*20*/2,
/*21*/3,
/*22*/3,
/*23*/4,
/*24*/2,
/*25*/3,
/*26*/3,
/*27*/4,
/*28*/3,
/*29*/4,
/*30*/4,
/*31*/5,
/*32*/1,
/*33*/2,
/*34*/2,
/*35*/3,
/*36*/2,
/*37*/3,
/*38*/3,
/*39*/4,
/*40*/2,
/*41*/3,
/*42*/3,
/*43*/4,
/*44*/3,
/*45*/4,
/*46*/4,
/*47*/5,
/*48*/2,
/*49*/3,
/*50*/3,
/*51*/4,
/*52*/3,
/*53*/4,
/*54*/4,
/*55*/5,
/*56*/3,
/*57*/4,
/*58*/4,
/*59*/5,
/*60*/4,
/*61*/5,
/*62*/5,
/*63*/6,
/*64*/1,
/*65*/2,
/*66*/2,
/*67*/3,
/*68*/2,
/*69*/3,
/*70*/3,
/*71*/4,
/*72*/2,
/*73*/3,
/*74*/3,
/*75*/4,
/*76*/3,
/*77*/4,
/*78*/4,
/*79*/5,
/*80*/2,
/*81*/3,
/*82*/3,
/*83*/4,
/*84*/3,
/*85*/4,
/*86*/4,
/*87*/5,
/*88*/3,
/*89*/4,
/*90*/4,
/*91*/5,
/*92*/4,
/*93*/5,
/*94*/5,
/*95*/6,
/*96*/2,
/*97*/3,
/*98*/3,
/*99*/4,
/*100*/3,
/*101*/4,
/*102*/4,
/*103*/5,
/*104*/3,
/*105*/4,
/*106*/4,
/*107*/5,
/*108*/4,
/*109*/5,
/*110*/5,
/*111*/6,
/*112*/3,
/*113*/4,
/*114*/4,
/*115*/5,
/*116*/4,
/*117*/5,
/*118*/5,
/*119*/6,
/*120*/4,
/*121*/5,
/*122*/5,
/*123*/6,
/*124*/5,
/*125*/6,
/*126*/6,
/*127*/7,
/*128*/1,
/*129*/2,
/*130*/2,
/*131*/3,
/*132*/2,
/*133*/3,
/*134*/3,
/*135*/4,
/*136*/2,
/*137*/3,
/*138*/3,
/*139*/4,
/*140*/3,
/*141*/4,
/*142*/4,
/*143*/5,
/*144*/2,
/*145*/3,
/*146*/3,
/*147*/4,
/*148*/3,
/*149*/4,
/*150*/4,
/*151*/5,
/*152*/3,
/*153*/4,
/*154*/4,
/*155*/5,
/*156*/4,
/*157*/5,
/*158*/5,
/*159*/6,
/*160*/2,
/*161*/3,
/*162*/3,
/*163*/4,
/*164*/3,
/*165*/4,
/*166*/4,
/*167*/5,
/*168*/3,
/*169*/4,
/*170*/4,
/*171*/5,
/*172*/4,
/*173*/5,
/*174*/5,
/*175*/6,
/*176*/3,
/*177*/4,
/*178*/4,
/*179*/5,
/*180*/4,
/*181*/5,
/*182*/5,
/*183*/6,
/*184*/4,
/*185*/5,
/*186*/5,
/*187*/6,
/*188*/5,
/*189*/6,
/*190*/6,
/*191*/7,
/*192*/2,
/*193*/3,
/*194*/3,
/*195*/4,
/*196*/3,
/*197*/4,
/*198*/4,
/*199*/5,
/*200*/3,
/*201*/4,
/*202*/4,
/*203*/5,
/*204*/4,
/*205*/5,
/*206*/5,
/*207*/6,
/*208*/3,
/*209*/4,
/*210*/4,
/*211*/5,
/*212*/4,
/*213*/5,
/*214*/5,
/*215*/6,
/*216*/4,
/*217*/5,
/*218*/5,
/*219*/6,
/*220*/5,
/*221*/6,
/*222*/6,
/*223*/7,
/*224*/3,
/*225*/4,
/*226*/4,
/*227*/5,
/*228*/4,
/*229*/5,
/*230*/5,
/*231*/6,
/*232*/4,
/*233*/5,
/*234*/5,
/*235*/6,
/*236*/5,
/*237*/6,
/*238*/6,
/*239*/7,
/*240*/4,
/*241*/5,
/*242*/5,
/*243*/6,
/*244*/5,
/*245*/6,
/*246*/6,
/*247*/7,
/*248*/5,
/*249*/6,
/*250*/6,
/*251*/7,
/*252*/6,
/*253*/7,
/*254*/7,
/*255*/8};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *buf = calloc(num + 1, sizeof(int));
    unsigned char *pbuf;
    int i, j, count;
    for (i = 0; i <= num; i++) {
        count = 0;
        buf[i] = i;
        pbuf = (char *)&buf[i];
        for (j = 0; j < sizeof(int); j++)
            count += count_byte[pbuf[j]];
        buf[i] = count;
    }
    *returnSize = num + 1;
    return buf;
}

// 8. String to Integer (atoi)
int myAtoi(char* str) {
    int minus;
    char *buf = calloc(12, sizeof(char));
    int len;
    unsigned long result;
    int overflow;
    
    while (*str == ' ')
        str++;

    if (*str == '-') {
        minus = 1;
	str++;
    } else if (*str == '+') {
	    minus = 0;
	    str++;
    } else
	    minus = 0;

    while (*str == '0')
        str++;
    
    len = 0;
    while (len < 11 && isdigit(*str))
        buf[len++] = *str++;

    if (len > 10) {
	    overflow = 1;
	    goto ret_result;
    }
    
    result = 0;
    overflow = 0;
    for (int i = 0; i < len; i++) {
	    result *= 10;
	    result += (buf[i] - '0');
	    if ((minus == 0 && result > 2147483647) ||
		(minus == 1 && result > 2147483648)) {
		    overflow = 1;
		    break;
	    }
    }

ret_result:
    printf("temp:%d %d %s %ld\n", minus, overflow, buf, result);
    if (overflow == 1 && minus == 1)
	    result = -2147483648;
    else if (overflow == 1 && minus == 0)
	    result = 2147483647;
    else if (minus == 1)
	    result = -result;

    return result;
}

// 6. ZigZag Conversion
char* convert(char* s, int numRows) {
    int len = strlen(s);
    int *index = calloc(len, sizeof(int));
    int i, j;
    char *ret = calloc(len + 1, sizeof(char));
    int ret_index;
    int rotate = (2 * numRows) - 2;

    if (rotate == 0)
	    rotate = 1;

    for (i = 0; i < len; i++) {
	    if ((i % rotate) <= (numRows - 1))
		    index[i] = (i % rotate);
	    else
		    index[i] = (rotate - (i % rotate));
    }

write_string:
    /* for (i = 0; i < len; i++) { */
    /* 	    printf("%d ", index[i]); */
    /* } */
    /* printf("\n"); */

    ret_index = 0;
    for (i = 0; i < rotate; i++) {
	    for (j = 0; j < len; j++) {
		    if (index[j] == i) {
			    /* printf("%c", s[j]); */
			    ret[ret_index++] = s[j];
		    }
        }
    }
    return ret;
}

// 5. Longest Palindromic Substring
char* longestPalindrome(char* s) {
	int start, end, index;
	int maxl;
	char *ret;
	int len = strlen(s);
	char *maxp;
	
	index = start = end = 0;
	maxl = 0;

	while (s[index]) {
		// get pivot
		start = end = index;
		while (start > 0 && s[start] == s[start - 1])
			start--;
		while (end < (len - 1) && s[end] == s[end + 1])
			end++;

		//printf("pivot=%d~%d\n", start, end);

		// get palindrome
		while (start > 0 && end < (len - 1) && s[start - 1] == s[end + 1]) {
			start--;
			end++;
		}

		// max?
		if (maxl < (end - start + 1)) {
			//printf("cur-max=%d~%d\n", start, end);
			maxp = &s[start];
			maxl = end - start + 1;
		}
		
		index++;
	}
	ret = calloc(maxl + 1, sizeof(char));
	memcpy(ret, maxp, maxl);
	return ret;
}

// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int max, cur_max, end;
    int counter[255];
    
    max = cur_max = end = 0;
    memset(counter, 0, sizeof(int)*255);
    
    while (end < len) {
        if (counter[s[end]] == 0) {
            counter[s[end]]++;
            cur_max++;
            end++;
        } else {
            int c;
            memset(counter, 0, sizeof(int)*255);
            if (max < cur_max)
                max = cur_max;
            cur_max = 0;
            c = s[end];
            // back to non-duplicated character??
            while (s[end-1] != c)
                end--;
        }
    }
    if (max < cur_max)
        max = cur_max;
    return max;
}

// 2. Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int c, l, r, v;
    struct ListNode *head, *prev, *cur;
    
    prev = NULL;
    c = 0;
    do {
        l = l1 ? l1->val : 0;
        r = l2 ? l2->val : 0;
        
        v = l + r + c;
        c = v / 10;
        
        cur = calloc(1, sizeof(*cur));
        cur->val = v % 10;
        
        if (!prev)
            head = cur;
        else
            prev->next = cur;
        prev = cur;
        
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    } while (l1 || l2);
    
    if (c) {
        cur = calloc(1, sizeof(*cur));
        cur->val = 1;
        prev->next = cur;
    }
    
    return head;
}
