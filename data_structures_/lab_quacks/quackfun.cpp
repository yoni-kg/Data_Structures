/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s)
{
  T add;
  T num=s.top();

  s.pop();

  if(s.empty())
  {
    s.push(num);
    return num;
  }
  else
  {
    add=sum(s);
    s.push(num);
    return (num+add);
  }
                // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of
 * square bracket characters, [, ], and other characters. This function will return
 * true if and only if the square bracket characters in the given
 * string are balanced. For this to be true,
 * all brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is balanced,
 * "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is balanced.
 *
 * You are allowed only the use of one stack in this function, and no other local variables.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
  stack<char> s;
  while(!input.empty())
  {
    if(input.front()=='[')
    {
      s.push(input.front());
    }

    else if(input.front()==']')
    {
      if(s.empty())
      {
        return false;
      }
      else
      {
        s.pop();
      }
    }
    input.pop();
  }

if(!s.empty())
{
  return false;
}
    return true;
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
    // optional: queue<T> q2;
    // Your code here
    int count, size, range;
    count=size=range= 1;
    int flag = 0;
    int last;
    T temp;

    while(!q.empty())
    {
      while(count>0)
      {
        count-=1;
        temp=q.front();
        q.pop();
        if(size%2==0)
        {
          s.push(temp);
        }
        else if(size%2==1)
        {
          q.push(temp);
        }
      }

      if(flag==0)
      {
        if(size%2==0)
        {
          for(int i=0; i<size; i++)
          {
            q.push(s.top());
            s.pop();
          }
        }
      }

      else if(flag == 1)
      {
        if(size%2==0)
        {
          for(int i=0; i<last; i++)
          {
          q.push(s.top());
          s.pop();
          }
          return;
        }
      }

      size+=1;
      count=size;
      if((count+range)>(int)q.size())
      {
        flag=1;
        count=q.size()-range;
        last=count;
      }
      else
      {
        range+=count;
      }
    }
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note The back of the queue corresponds to the top of the stack!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    bool retval = true; // optional
    T stemp; // rename me
    T qtemp; // rename :)

    // Your code here
    if(s.empty())
    {
      return true;
    }
    stemp=s.top();
    s.pop();
    retval=verifySame(s,q);
    qtemp=q.front();
    q.pop();
    if(qtemp!=stemp)
    {
      s.push(stemp);
      q.push(qtemp);
      retval=false;
      return retval;
    }
    else
    {
      s.push(stemp);
      q.push(qtemp);
      return retval;
    }
}
}
