var express = require('express');
var app = express();
var path = require('path');
var http = require("http");
var ejs = require("ejs");

var server = http.createServer(app);
app.set('view engine', 'ejs');  //tell Express we're using EJS
app.set('views', __dirname + '/views');  //set path to *.ejs files

var markov;
var exefile='../python/main.py';

const exec = require('child_process').exec;


app.get('/', function (req, res) {
    res.render('index', {sentence : '', username : ''});

})

app.get('/:username/:len', function(req, res){
    var username = req.params.username;
    var length = req.params.len;
    console.log(username+length);
  
    exec('python '+exefile+' '+username+' '+length, (error, stdout, stderr) => {
      if (error) {
      console.error(`exec error: ${error}`);
      return;
      }
    
    markov=`${stdout}`;
    console.log(markov);
    // res.render('index', {sentence : markov});
    res.render('index', {sentence : markov, username : username});
    });
})


server.listen(process.env.PORT || 3000, process.env.IP || "0.0.0.0", function(){
  var addr = server.address();
  console.log("Markovian Chain hosting at:", addr.address + ":" + addr.port);
});