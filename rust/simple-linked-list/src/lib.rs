use std::iter::FromIterator;

pub struct SimpleLinkedList<T> {
    head: Option<Box<Node<T>>>,
}

pub struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

impl<T> SimpleLinkedList<T> {
    pub fn new() -> Self {
        SimpleLinkedList { head: None }
    }

    pub fn len(&self) -> usize {
        let mut len = 0usize;
        let mut current = &self.head;
        loop {
            match current {
                Some(ref node) => {
                    len += 1;
                    current = &node.next;
                }
                None => {
                    break;
                }
            }
        }
        len
    }

    pub fn push(&mut self, element: T) {
        self.head = Some(Box::new(Node::<T> {
            data: element,
            next: self.head.take(),
        }));
    }

    pub fn pop(&mut self) -> Option<T> {
        match self.head.take() {
            Some(mut node) => {
                self.head = node.next.take();
                Some(node.data)
            }
            None => None,
        }
    }

    pub fn peek(&self) -> Option<&T> {
        match self.head {
            Some(ref n) => Some(&n.data),
            None => None,
        }
    }

    pub fn rev(mut self) -> SimpleLinkedList<T> {
        let mut ret = SimpleLinkedList::new();
        loop {
            match self.head {
                Some(_) => ret.push(self.pop().unwrap()),
                None => break,
            }
        }
        ret
    }
}

impl<T> FromIterator<T> for SimpleLinkedList<T> {
    fn from_iter<I: IntoIterator<Item = T>>(iter: I) -> Self {
        let mut ll = SimpleLinkedList::new();
        for i in iter {
            ll.push(i);
        }
        ll
    }
}

// In general, it would be preferable to implement IntoIterator for SimpleLinkedList<T>
// instead of implementing an explicit conversion to a vector. This is because, together,
// FromIterator and IntoIterator enable conversion between arbitrary collections.
// Given that implementation, converting to a vector is trivial:
//
// let vec: Vec<_> = simple_linked_list.into_iter().collect();
//
// The reason this exercise's API includes an explicit conversion to Vec<T> instead
// of IntoIterator is that implementing that interface is fairly complicated, and
// demands more of the student than we expect at this point in the track.

impl<T> Into<Vec<T>> for SimpleLinkedList<T> {
    fn into(mut self) -> Vec<T> {
        let mut ret = vec![];
        loop {
            match self.head {
                Some(_) => ret.push(self.pop().unwrap()),
                None => break,
            }
        }
        ret.reverse();
        ret
    }
}
