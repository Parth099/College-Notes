class ListNode<T> {
    public readonly data: T; //no null
    public next: ListNode<T> | null = null; //easier to debug if public

    //constructors
    constructor(data: T, next?: ListNode<T>) {
        this.data = data;
        if (next) {
            this.next = next;
        }
    }
}

class LinkedList<T> {
    //dont want people seeing internal vars
    private head: ListNode<T> | null = null;

    constructor(initVal?: T) {
        if (initVal) {
            this.head = new ListNode<T>(initVal);
        }
    }

    add(data: T) {
        if (this.head === null) {
            this.head = new ListNode<T>(data);
            return;
        }
        //reads until the next spot is null
        let curr: ListNode<T> = this.head!; //at this point head is non null
        while (curr.next != null) {
            console.log(`${curr.data} --> `);
            curr = curr.next;
        }
        curr.next = new ListNode<T>(data);
    }

    removebyIndex(index: number): boolean {
        //head remove call
        if (index == 0) {
            if (this.head && this.head.next) {
                this.head = this.head.next;
            } else {
                this.head = null;
            }
            return true;
        }

        let counter = 0;
        let curr: ListNode<T> | null = this.head;

        while (curr != null) {
            if (counter === index - 1) {
                //we need the node before
                if (curr.next == null) {
                    return false;
                }
                curr.next = curr.next.next;
                return true;
            }
            curr = curr.next;
        }

        return false;
    }

    printList() {
        let output: string = "";
        let curr: ListNode<T> | null = this.head;
        while (curr != null) {
            output += `${curr.data} --> `;
            curr = curr.next;
        }
        console.log(output + "null");
    }
}

/* 
//testing LL
const L = new LinkedList(4);
L.add(0);
L.add(99);

L.removebyIndex(1);
L.removebyIndex(1);
L.removebyIndex(0);

L.add(17);

L.printList();
*/



