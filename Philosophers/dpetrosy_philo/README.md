<a name="readme-top"></a>
<div align="center">
  <!-- Logo -->
  <a href="https://github.com/dpetrosy/42-Philosophers">
  <img src="README_files/logo.png" alt="Logo" width="80" height="80">
  </a>

  <!-- Project Name -->
  <h1>Philosophers Project</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>42 Yerevan Philosophers</b><br>
	  For further information about 42cursus and its projects, please refer to <a href="https://github.com/dpetrosy/42cursus"><b>42cursus repo</b></a>.
  </p>

  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/dpetrosy/42-Philosophers?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/dpetrosy/42-Philosophers?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/dpetrosy/42-Philosophers?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/dpetrosy/42-Philosophers?style=for-the-badge" />
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-mandatory-part">🔷 Mandatory Part</a>
    <span> · </span>
	  <a href="#-bonus-part">🌟 Bonus Part</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
  </h3>
</div>

---

## 📜 About Project

> 42 School Philosophers project designed around Edsger Dijkstra's famous [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). \
> For this project, we must learn about concurrent programming and shared memory synconization.

For detailed information, refer to the [**subject of this project**](README_files/philo_subject.pdf).

	🚀 TLDR: This project is an introduction to the basics of multithreading and multiprocessing.
    	 Work on the same memory space, learn about mutexes, semaphores, and shared memory.

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 🔷 Mandatory Part

#### The subject describes the problem as follows:

* One or more philosophers sit at a round table.
* There is a large bowl of spaghetti in the middle of the table.
* The spaghetti can only be eaten with two forks.
* There are only as many forks as there are philosophers.
* Each philosopher successively eats, sleeps and thinks.
* If a philosopher hasn't eaten in a certain timeframe, he will die of starvation.
* Philosophers cannot communicate with each other.

#### The program takes the following arguments:

`./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
[number_of_times_each_philosopher_must_eat]`

* **```number_of_philosophers```**: the number of philosophers around the table.
* **```time_to_die```**: a number representing the time in milliseconds a philosopher has to live after a meal. If a philosopher hasn’t started eating time_to_die milliseconds after the beginning of his last meal or the beginning of the simulation, he will die.
* **```time_to_eat```**: a number representing the time in milliseconds a philosopher takes to finish his meal. During that time, the philosopher keeps his two forks in hand.
* **```time_to_sleep```**: the time in milliseconds that a philosopher spends sleeping.
* **```number_of_times_each_philosopher_must_eat```**: an optional argument that allows the program to stop if all the philosophers have eaten at least that many times. If this argument is not specified, the simulation carries on unless a philosopher dies.

#### Program logs philosophers actions in this format. X is philosopher ID:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## 🌟 Bonus Part

For the bonus part of this project, the problem is the same with a few differences: philosophers are now processes, \
and the forks are now counting semaphores. The forks are arranged at the center of the table when not in use, and \
any philosopher can take any fork.

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the mandatoy part, run:

```shell
$ cd path/to/philo && make
```

To compile the bonus part, run:

```shell
$ cd path/to/philo_bonus && make
```

**2. How to run the program**

Run the program with the following arguments:
```shell
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philo_must_eat]
```

The arguments must be integers between 0 and INT_MAX representing a time in milliseconds. For example:

```shell
./philo 5 800 200 200 7
```

If the arguments are valid, the program will output the actions of each philosopher until one of them dies or until all of them have eaten `number_of_times_each_philo_must_eat`, if specified. \
Bonus part takes the same arguments, but needs to run executalbe `philo_bonus` instead of `philo`.

