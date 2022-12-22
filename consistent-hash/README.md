This is a project that implements consistent hashing, as put forth in my project proposal.
I had suggested a circular linked list with an array as a means of implementing this, but midway through my work
I realised an AVL tree, with each node having a linked list attached to it was a better way of implementing it.

To run my code, compile the files lists.c, tests.c and trees.c together, after calling the appropriate test function from the main() method of tests.c.

Consistent hashing is a way to distribute keys around a given set of anchors such that remapping is minimal. It does this
by hashing all the anchors onto a circle, and mapping every key to the anchor on it's immediate right. This has the nice effect of only having to remap the keys linked to a single anchor every time an anchor is destroyed or added.

I implemented this using an AVL tree of anchor hashes, with each node having a linked list to store the keys attached to an anchor. Inserting an deleting an anchor works as in a normal BST, leaving us to remap keys from and to the inorder successors of the inserted and deleted values respectively. 

For inserting or deleting a key we search for it in the tree. If we end up at a value greater than our hash, we are done, else we go to the successor of our value.

Test case 1: Showing that every key will map to the same anchor in the case with one anchor

Test case 2: Showing that the remapping of keys occurs as intended

Test case 3: Showing that the remapping of keys occurs as intended even in edge cases such as a node being added after the last key, which is currently mapped to the smallest node

Test case 4: Showcasing a common technique used to balance loads across distributed server systems, where multiple 'copies' of servers are hashed around the ring

Test case 5: Showing keys are remapped correctly upon deletion of an anchor

Test case 6: Showing the addition of new keys is done correctly

Test case 7: Showing that the keys of an anchor can emptied without problems

Test case 8: Showing that every anchor can be emptied correctly

Test case 9: Showing that every anchor can be deleted properly

Test case 10: Showcasing the advantage of consistent hashing over regular hashing, with duplicated anchors and them being deleted one by one. This shows how a relatively small number keys need to be remapped.

Note: Test cases have used a small number of anchors and keys for the sake of readability.