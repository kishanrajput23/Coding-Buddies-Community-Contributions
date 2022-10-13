class Solution{

    static String decodedString(String s){

        ArrayDeque<Integer>count=new ArrayDeque<Integer>();

        ArrayDeque<String>c=new ArrayDeque<String>();

        int i=0;

        String ans="";

        while(i<s.length())

        {

            if(Character.isDigit(s.charAt(i)))

            {

                int temp=0;

                while(Character.isDigit(s.charAt(i)))

                {

                    temp=(temp*10)+(s.charAt(i)-'0');

                    i++;

                }

                count.push(temp);

            }

            else if(s.charAt(i)==']')

            {

                StringBuilder temp=new StringBuilder();

                while((c.peek()).equals("[")==false)

                {

                    temp.append(c.pop());

                }

                c.pop();

                int j=count.pop();

            StringBuilder t1=new StringBuilder();

                while(j>=1)

                {

                    t1.append(temp);

                    j--;

                }

               c.push(t1.toString());

                i++;

}

            else

            {

                c.push(""+s.charAt(i));

                i++;

            }

        }

        StringBuilder ans1=new StringBuilder(c.pop());

        while(c.isEmpty()==false)

        {

            if(c.peek().equals("[")==false && c.peek().equals("]")==false)

            {

                ans1.append(c.pop());

            }

            else c.pop();

        }

        return ans1.reverse().toString();

    }

}
