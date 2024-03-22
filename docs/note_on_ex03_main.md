
// Note 1 about the push method in stack
/*
std::stack does not provide a push_front method. It only provides a push method, which adds elements to the "top" of
the stack. The "top" of the stack, when using the default underlying container (std::deque), corresponds to the back
of the container. Thus, push on a std::stack effectively calls push_back on its underlying container, which, in the
context of std::deque, adds elements to the end.

The top of the container in all the underlying container of the stack is the back of the container, and this for the
simple fact that for a vector is way more efficient to add elements at the end of the container than at the
beginning. For a deque and for a list actually it doesn't matter, but the stack is implemented with a deque by
default, so the top of the stack is the back of the deque.
*/