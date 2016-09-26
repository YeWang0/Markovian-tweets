from user_timeline import *
import sys
import ctypes
import subprocess
import os.path

if __name__ == '__main__':

    if len(sys.argv) < 2:
        sys.stderr.write('Error: missing parameters\n')
        sys.exit(1)
        
    user_name = sys.argv[1]
    markovLength = 1
    if len (sys.argv) == 3:
        markovLength = int(sys.argv [2])

    # print user_name,markovLength
    result=''
    result+= '<hr />'
    result+= '<h4>Log:</h4>'
    result+= '<hr />'
    cpp_path='../cpp/'
    # user_name='Ye__Wang'
    # user_name='BarackObama'
    # user_name='HillaryClinton'
    # user_name='realDonaldTrump'

    filename='Timeline_'+user_name+'.txt'
    
    
    if not os.path.isfile('../result/'+filename):
        result+= ' getting user timeline...'
        result+=  '<hr />'
        result+=  " new file created..."
        result+=  '<hr />'
        #create user timeline file in /result
        # example: /result/Timeline_BarackObama.txt
        get_user_timeline_by_name(user_name)
        
    if not os.path.isfile('./a.out'):
        result+=  ' compiling cpp...'
        result+=  '<hr />'
        # compile markcovian maping code
        bashCommand='g++ -std=c++11 '+cpp_path+'markovian_tweets.cpp '+cpp_path+'functions.cpp'
        result+=  bashCommand
        result+=  '<hr />'
        subprocess.Popen(bashCommand.split(),stdout=subprocess.PIPE,stderr=subprocess.PIPE).communicate()
    
    result+=  ' building map...'
    result+=  '<hr />'
    # execute markcovian maping code
    bashCommand='./a.out ../result/'+filename+' '+str(markovLength)
    result+=  bashCommand
    result+=  '<hr />'
    process = subprocess.Popen(bashCommand.split(),stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    output, error = process.communicate()
    result+=  ' getting output...'
    result+=  '<hr />'
    if not output:
        print "<h2>Invalid twitter name</h2>"
    else:      
        print "<div id='generated_tweet'>"
        print "<h2>Auto generated tweet</h2>"
        print "<h4>User name: "+user_name+"</h4>"
        print "<h4>Auto Tweet: "+output+"</h4>"
        print "</div>"

    print result