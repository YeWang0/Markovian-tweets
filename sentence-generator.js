var express = require('express');
var app = express();
var markov;
var exefile='sentence-generator.py'
var filename='portrait-of-the-artist.txt';
var chain_len=4
const exec = require('child_process').exec;
exec('python ./twitter/'+exefile+' ./twitter/result/'+filename+' '+chain_len, (error, stdout, stderr) => {
if (error) {
console.error(`exec error: ${error}`);
return;
}

markov=`${stdout}`;
console.log(markov);
});

app.get('/', function (req, res) {
  res.send(markov);
  
	exec('python ./twitter/'+exefile+' ./twitter/result/'+filename+' '+chain_len, (error, stdout, stderr) => {
    if (error) {
    console.error(`exec error: ${error}`);
    return;
    }
  
    markov=`${stdout}`;
    console.log(markov);
	});
   
    
})


var server = app.listen(8081, function () {
  
  console.log(`node start...`);
  // console.log(`stderr: ${stderr}`);

})