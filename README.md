# How to use

1. Clone this repository to the root directory of your libft repository.
2. Run the make command inside this repository.


## 1. Clone this repository
```
$ cd /path/to/your/libft/directory
$ git clone https://github.com/usatie/libft-tester-tokyo.git
$ cd libft-tester-tokyo
```

* If you would like to clone this repository to somewhere else, you can.
In that case, please run the make command like this.
```
$ make LIBFT_DIR=/path/to/your/libft/dir
```

## 2. Test Mandatory functions
```
$ make all
```

<img width="1388" alt="Screen Shot 2022-04-18 at 9 34 55" src="https://user-images.githubusercontent.com/7609060/163738262-2070f78d-83e2-4585-83d4-c65edbcdcddb.png">

## 3. Test Bonus functions
```
$ make bonus
```

## 4. Test individual function
```
$ make strlen
$ make atoi
$ make strnstr
```

<img width="1386" alt="Screen Shot 2022-04-18 at 9 35 27" src="https://user-images.githubusercontent.com/7609060/163738259-a04237e5-d66d-4694-b323-8739b194fe12.png">

## 5. Test Norminette & coding rules
```
$ make norm
```

<img width="1369" alt="Screen Shot 2022-04-18 at 15 27 40" src="https://user-images.githubusercontent.com/7609060/163765260-3fad885b-e00a-4b3f-9468-cc998ae5cb24.png">


# Thanks for trying it out!
If you notice anything or want to add some test cases, feel free to send issues/PRs!

This project is inspired by these project, and imported many cases from them too.
Thanks a lot!
- https://github.com/Tripouille/libftTester
- https://github.com/alelievr/libft-unit-test
