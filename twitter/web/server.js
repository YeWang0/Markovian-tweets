var express = require('express');
var app = express();
var path = require('path');
var http = require("http");
var ejs = require("ejs");


app.set('view engine', 'ejs');  //tell Express we're using EJS
app.set('views', __dirname + '/views');  //set path to *.ejs files



var markov;
var exefile='../python/main.py';

const exec = require('child_process').exec;


app.get('/', function (req, res) {
//   res.send(markov);
//   res.sendFile(path.join(__dirname + '/index.html'));
//render index.ejs file
    res.render('index', {sentence : ''});

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
     res.render('index', {sentence : markov});
     console.log(markov);
    //  res.send({sentence : 'markov'});
    });
})


// var generateSentence = function(length){
//     var markov;
//     exec('python'+ ' ' +exefile+' '+filename+' '+length, (error, stdout, stderr) => {
//     if (error) {
//     console.error(`exec error: ${error}`);
//     return;
//     }
 
//     markov=`${stdout}`;
//     console.log("generat:" + markov);
// 	return markov;
        
//     });
//     // while(true){
//     //     if(markov!=null)
//     //         return markov;
//     // }
    
	
// }

var server = app.listen(8081, function () {
  
  console.log(`node start...`);
  // console.log(`stderr: ${stderr}`);

})