### The Algorithm
Mark and Sweep garbage collection was first described by John McCarthy in 1960, primarily for managing memory in ((lisp)).

It's a two-phase algorithm:
1. Mark Phase: Traverses the object graph, marking all reachable objects.
    - the "root objects" are the objects directly referenced by stack frame
    - the mark phase has two sub-phases:
        - in the first half we mark all of the root objects
        - in the second half (also called tracing phase) we mark all the objects reachable by the previous root objects
2. Sweep Phase: Scan memory, collecting all unmarked objects, which are considered garbage.
    - to scan the memory you have to save the references to every object you allocated

**Note** We don't keep track of how many times a particular object is referenced, like we did with reference counting! Instead, **we keep track of which objects are referenced in each stack frame** and then **traverse our container objects looking for any other referenced objects**. That's what "traverse the object graph" means - a fancy way of saying "look for objects".