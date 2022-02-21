## Singly Linked-List

Variation of the Linked-List which uses only a single pointer for chaining
the Nodes together into a list - 



### Operations

#### Getting

Implementing standalone cases for each possible position.

* Head: O(1) - Getting the value directly from the Head-Node
* Tail: O(1) - Getting the value directly from the Tail-Node
* At Index: O(N) - Using the Node-Finding helper for getting the Node
  at a specific index.

Checks: Using the Size for determining whether the retrieval is possible.


#### Inserting

Implementing special cases for Head and Tail insertions, which allow
handling the list being empty, and reusing them for Index insertion -
using the index and size to check whether the insertion is being performed
at the Head / Tail.

* Head: O(1) - Prepending a new Node. 
* Tail: O(1) - Appending a new Node.
* At Index: O(N) - Checking for Head and Tail cases and then using the
general case, which retrieves the Previous-Node for re-chaining.
  
Checks: Using the Size for determining whether the insertion is valid -
allowing the insertion to be performed at the index AFTER the last Node
(same as appending to the Tail).


#### Deleting

Implementing a single generalized case for deleting any Node at any index
and reusing it for the Head and Tail cases - much easier this way.

* Head: O(1) - Using the general case (Terminates immediately
  using the Dummy-Node).
* Tail: O(N) - Using the general case (Having to search for the pre-last
  Node in any case, no matter the implementation / approach).
* At Index: O(N) - Retrieving the node previous to the index, re-chaining
  and performing additional logic to support deletions from Head / Tail,
  as well as the list becoming empty.

Checks: Using the Size for determining whether the deletion can only
address and delete elements from the actual bounds of the list (ignoring
the deletion otherwise).

**Important**: Tail-Deletion is always slow no matter the implementation -
unless the previous-pointer is kept, there is no way to access the
pre-last Node, except iterating.



### Techniques

#### Size Tracking

Keeping track of size / number of Nodes in the list at a time, not only
for being able to tell the length, but also to support the following
internal logic:
* Checking whether a specific Get / Insertion / Deletion request
  uses a valid index, enabling unnecessary work to be avoided.
* Checking whether the Insertion / Deletion via Index is actually
  targeted at the Tail and use a specialized logic / case.
* Determining whether the List is empty or not in constant time.


#### Node Finding

Using a single central utility / helper for finding / retrieving a Node
at a specific index and returning it.

**Extension**: Being able to return the Node by the Index "-1" / Node that
is previous to the Head, which is used for serving deletions at the Head (
getting the previous-Node for the Head).


#### Dummy Node

Using a reusable Dummy-Node in the Node-Finding routine, which is
initially set to pointing to the Head-Node, allowing the Node-Finding
to return a Node which is previous to the Head-Node / Node at the index of
"-1" (Before the 0th index).

