1. what is the difference between recursive call and iteration?
for recursive call, the subproblem would always look the same to the original problem. Tree is an excellent candidate for recursive call. the structure looks like the follow:
function(treenode){
if(treenode==NULL) return something;
function(treenode->left);
function(treenode->right);
}
for recursive call, the condition is a if statement, for iteration, the condition would be a while statement:
function(treenode){
while(treenode){
temp=treenode;
treenode=treenode->left
do something;
treenode=temp->right;
do something
}
}

2. technique for leading and trailing pointers:
because a treenode has two children, the end condition would be rather difficult to write. If we employ the leading and trailing pointer technique:
while(x)
x=y;
if()y=y->left;
y=y->right;

3. technique of doing iteration via recursive call.
for(){
i++;
recursivecall(something)
}
is the equivolent of 
you can directly pass i through the argument of the recursive call.
recursivecall(something, ++i)

4. example recall and analysis:
matrix_print of a tree. the reason I did not come up with the solution is because I failed to see the recursive structure in it. I approached it to see how I can systematically write all the element into a structure. Tree is recursive can only be the following structure
function(root)
dosomething with root
function(root->left)
function(root->right)
therefore this should be approached from offset from root problem.

5. daily routine: 
writing dailynode every morning, recalling the technique points from the previous day of exercise.

6. container:
queue q;
q.front() print out the front element;
q.pop() pop out the front element, returning type is void;
q.push() push an element into the queue, at the back;
q.emplace() this is a newer implementation but doing push, need more indepth knowledge to actually understand the difference.

the major difference at the implementation of stack, queue is that it doesn't offer iterators over it.

7. template<typename T>
BST<T>::BST() this is constructor
also in the h file, need to specify
template  class<int>
template

























