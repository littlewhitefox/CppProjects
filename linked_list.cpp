#include <cstdio>
#include <cstdlib>

struct test_struct {
    int val;
    struct test_struct *next;
};

struct test_struct *head = nullptr;
struct test_struct *curr = nullptr;

struct test_struct *create_list(int val) {
    printf("\n Creating list with head node as [%d]\n", val);
    auto *ptr =
            (struct test_struct *) malloc(sizeof(struct test_struct));
    if (nullptr == ptr) {
        printf("\n Node creation failed \n");
        return nullptr;
    }
    ptr->val = val;
    ptr->next = nullptr;

    head = curr = ptr;
    return ptr;
}

struct test_struct *add_to_list(int val, bool add_to_end) {
    if (nullptr == head) {
        return (create_list(val));
    }

    if (add_to_end)
        printf("\n Adding node to end of list with value [%d]\n", val);
    else
        printf("\n Adding node to beginning of list with value [%d]\n", val);

    auto *ptr =
            (struct test_struct *) malloc(sizeof(struct test_struct));
    if (nullptr == ptr) {
        printf("\n Node creation failed \n");
        return nullptr;
    }

    ptr->val = val;
    ptr->next = nullptr;

    if (add_to_end) {
        curr->next = ptr;
        curr = ptr;
    } else {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

struct test_struct *search_in_list(int val, struct test_struct **prev) {
    struct test_struct *ptr = head;
    struct test_struct *tmp = nullptr;
    bool found = false;

    printf("\n Searching the list for value [%d] \n", val);

    while (nullptr != ptr) {
        if (ptr->val == val) {
            found = true;
            break;
        } else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if (found) {
        if (prev)
            *prev = tmp;
        return ptr;
    } else {
        return nullptr;
    }
}

int delete_from_list(int val) {
    struct test_struct *prev = nullptr;
    struct test_struct *del;

    printf("\n Deleting value [%d] from list \n", val);

    del = search_in_list(val, &prev);
    if (del == nullptr) {
        return -1;
    } else {
        if (nullptr != prev)
            prev->next = del->next;

        if (del == curr) {
            curr = prev;
        } else if (del == head) {
            head = del->next;
        }
    }

    free(del);

    return 0;
}

void print_list() {
    struct test_struct *ptr = head;

    printf("\n -----Printing List Start-----\n");
    while (nullptr != ptr) {
        printf("\n [%d] \n", ptr->val);
        ptr = ptr->next;
    }
    printf("\n -----Printing List End-----\n");
}

int main() {
    int i, ret;
    struct test_struct *ptr;

    print_list();

    for (i = 5; i < 10; i++)
        add_to_list(i, true);

    print_list();

    for (i = 4; i > 0; i--)
        add_to_list(i, false);

    print_list();

    for (i = 1; i < 10; i += 4) {
        ptr = search_in_list(i, nullptr);
        if (nullptr == ptr) {
            printf("\n Search [val = %d] failed, no such element found\n", i);
        } else {
            printf("\n Search passed [val = %d]\n", ptr->val);
        }

        print_list();

        ret = delete_from_list(i);
        if (ret != 0) {
            printf("\n Delete [val = %d] failed, no such element found\n", i);
        } else {
            printf("\n Delete [val = %d] passed \n", i);
        }

        print_list();
    }
    return 0;
}
