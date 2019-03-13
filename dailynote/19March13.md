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

8. git work flow:
version control, testout the changes before merge them with the master.
git config: provide your info regarding your commit;
git diff: show the differences between current file and previous files;
git init: to initialize a git tracking system on this particular depository, there would be a .git file in the repository;
git branch branchname: create a branch. for instance today, I want to work on heap related topics, so I would create a branch called heap/ the idea of branch is that it can be tested before merged with master branch.
git checkout master or branchname, switch between master and branch
git checkout master, and git merge branchname
git log, show all the commits: if you find yourself in a situation where the current things doesn't work and want to go back to previous version, that can be done.

how to rollback back commits?
to start a day's work, first create a branch of the master, such that this would be the starting point of your day.
at that point, the state repository would be empty, and all the diff would be empty as well.
in order to test out files, you will have to save them compile them, whenever it works, add and commit those changes.
if there would be circumstances that the new changes messes up with the code, just do the following:
git checkout filename
this way, your code would be back to the last time you commited that file.
after a day's work, if everything in this branch works, we want to merge this branch to the master branch and them delete the branch.
git checkout master
git merge branchname
git branch -d branchname
(in a company repository, you do git pull before git push)
git push
(there are a lot more advanced topics in git such as version conflict, what if both of you works on the same portion of the master file? but for the time being, the above work flow and commands should be sufface)


OBSERVATION:
oversation on my working condition: 
7-10 are the three hours that I can be extremely productive in recalling and should be used as such.

a short break at around 10, 
end the morning session at around 12

a break would be worranted after lunch, take care of personal higyen and stuff, take a cup of coffee if needed.























