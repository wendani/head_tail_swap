struct node {
    struct node *next;
};

struct node *head_tail_swap(struct node *head) {
    if (!head)
        return NULL;
    if (!head->next)
        return head;
       
    h = head;
    h_next = h->next;
    if (!h_next->next) {
        h_next->next = h;
        h->next = NULL;
        return h_next;
    }
       
    prev = h;
    nxt = h_next;
    while (nxt->next) {
        prev = nxt;
        nxt->next;
    }
    nxt->next = h_next;
    prev->next = h;
    h->next = NULL;
    return nxt;

}
