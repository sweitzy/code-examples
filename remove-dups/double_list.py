# Adapted from:
#  http://ls.pwd.io/2014/08/singly-and-doubly-linked-lists-in-python/

import pdb

class Node(object):
 
    def __init__(self, data, prev, next):
        self.data = data
        self.prev = prev
        self.next = next
 
 
class DoubleList(object):
 
    head = None
    tail = None
 
    def append(self, data):
        new_node = Node(data, None, None)
        if self.head is None:
            self.head = self.tail = new_node
        else:
            new_node.prev = self.tail
            new_node.next = None
            self.tail.next = new_node
            self.tail = new_node
        return new_node
 
    def remove(self, node_value):
        current_node = self.head
 
        while current_node is not None:
            if current_node.data == node_value:
                # if it's not the first element
                if current_node.prev is not None:
                    current_node.prev.next = current_node.next
                    # check if last element
                    if current_node.next is not None:
                        current_node.next.prev = current_node.prev
                    else:
                        self.tail = current_node.prev
                else:
                    # otherwise we have no prev (it's None), head is the next one, and prev becomes None
                    self.head = current_node.next
                    # check if we only have one element
                    if self.head is not None:
                        current_node.next.prev = None
                    else:
                        self.tail = None
 
            current_node = current_node.next
 
    def remove_direct(self, current_node):
#        pdb.set_trace()
        # if it's not the first element
        if current_node.prev is not None:
            current_node.prev.next = current_node.next
            # check if last element
            if current_node.next is not None:
                current_node.next.prev = current_node.prev
            else:
                self.tail = current_node.prev
        else:
            # otherwise we have no prev (it's None), head is the next one, and prev becomes None
            self.head = current_node.next
            # check if we only have one element
            if self.head is not None:
                current_node.next.prev = None
 
 
    def show(self):
        print("Show list data:")
        current_node = self.head
        while current_node is not None:
            print(current_node.prev.data if hasattr(current_node.prev, "data") else None, end=" ")
            print (current_node.data, end=" ")
            print (current_node.next.data if hasattr(current_node.next, "data") else None)
 
            current_node = current_node.next
        print("*"*50)
 
    def to_list(self):
        data_list = []
        current_node = self.head
        while current_node is not None:
            data_list.append(current_node.data)
            current_node = current_node.next
        return data_list
 
if __name__ == '__main__':
    d = DoubleList()
 
    d.append(5)
# bug in original code!
#    d.remove(5)
    d.append(6)
    d.append(50)
    d.append(30)
# bug in original code
#    d.remove(30)

    d.show()
    print('LIST:', d.to_list())
 
    d.remove(50)
    d.remove(5)
 
    d.show()
