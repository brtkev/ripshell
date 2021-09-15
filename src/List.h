
typedef struct NodeString{
    char * data;
    struct NodeString* next;
    struct NodeString* previous;
} NodeString;

// typedef struct NodeString NodeString;

NodeString * newNodeString(){
    NodeString * node = (NodeString *)malloc(sizeof(NodeString));
    node->data = (char *)malloc(sizeof(char));
    node->next = node->previous = NULL;
    return node;
}


typedef struct ListString
{
    int size;
    NodeString* head;
    NodeString* tail;
}ListString;

ListString newListString(){
    ListString list = {
        .head = NULL,
        .tail = NULL,
        .size = 0
    };
    return list;
}

void ListStringPush(ListString * this, char * string){
    NodeString * newNode = newNodeString();
    strcpy(newNode->data, string);
    if(this->head == NULL){
        this->head = this->tail = newNode;
    }else{
        newNode->previous = this->tail;
        this->tail->next = this->tail = newNode;
    }
    this->size++;
}

void ListStringFree(ListString * this){
    NodeString * iter = this->head;
    while (iter != NULL)
    {
        NodeString * nextNode = iter->next;
        free(iter->data);
        free(iter);
        iter = nextNode;
    }
    this->head = this->tail = NULL;

}

void ListStringPrint(ListString this){
    NodeString* iter = this.head;
    while (iter != NULL){
        puts(iter->data);
        iter = iter->next;
    }
}

char * ListStringFront(ListString this){
    return this.head->data;
}