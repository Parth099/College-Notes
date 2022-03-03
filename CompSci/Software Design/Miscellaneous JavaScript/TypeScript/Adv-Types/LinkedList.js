"use strict";
class ListNode {
    //constructors
    constructor(data, next) {
        this.next = null; //easier to debug if public
        this.data = data;
        if (next) {
            this.next = next;
        }
    }
}
class LinkedList {
    constructor(initVal) {
        //dont want people seeing internal vars
        this.head = null;
        if (initVal) {
            this.head = new ListNode(initVal);
        }
    }
    add(data) {
        if (this.head === null) {
            this.head = new ListNode(data);
            return;
        }
        //reads until the next spot is null
        let curr = this.head; //at this point head is non null
        while (curr.next != null) {
            console.log(`${curr.data} --> `);
            curr = curr.next;
        }
        curr.next = new ListNode(data);
    }
    removebyIndex(index) {
        //head remove call
        if (index == 0) {
            if (this.head && this.head.next) {
                this.head = this.head.next;
            }
            else {
                this.head = null;
            }
            return true;
        }
        let counter = 0;
        let curr = this.head;
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
        let output = "";
        let curr = this.head;
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
