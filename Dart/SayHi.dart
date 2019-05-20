import 'dart:async';

const oneSecond = Duration(seconds: 1);
const twoSeconds = Duration(seconds: 2);
const threeSeconds = Duration(seconds: 3);

/*A future is a Future<T> object, which represents an asynchronous operation that produces a result of type T.
If the result isn’t a usable value, then the future’s type is Future<void>. */

/*The async and await keywords are part of the Dart language’s asynchrony support. 
They allow you to write asynchronous code that looks like synchronous code and doesn’t use the Future API*/

Future<void> alpha() async {
  String name = "alpha";
  var talk = await sayHi(threeSeconds,name);
  print(talk);
}

Future<void> beta() async {
  String name = "beta";
  var talk = await sayHi(oneSecond,name);
  print(talk);
}

Future<void> gamma() async {
  String name = "gamma";
  var talk = await sayHi(twoSeconds, name);
  print(talk);
}

void delta(){
  String name = "delta";
  String talk = "Hello! I'm " + name;
  print(talk);
}

main() {
  print("Program Started...");
  alpha();
  beta();
  gamma();
  delta();
  print("Called all the functions!");
}

Future<String> sayHi(waitTime, who) =>
    Future.delayed(waitTime, () => "Hello! I'm " + who);
