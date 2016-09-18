import re

def url_remove(tweet):

   return  re.sub(r'http\S+', '', tweet)

def hashtag_remove(tweet):
    return re.sub(r'[#@]\S+','',tweet)

def rt_remove(tweet):
    return re.sub(r'RT ','',tweet)

def tweet_cleanup(tweet):
    tweet=url_remove(tweet)
    tweet=hashtag_remove(tweet)
    tweet=rt_remove(tweet)
    return tweet
