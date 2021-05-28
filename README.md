# Wineyard
Spring arrived into the vineyards (parent process) named "Fine Wine Good Health" . The under-steward (first child process) of the vineyards 
each morning checks the  state of the vineyards parts.  (The parts are named: Brilliant Land,  Sparkling Ground, Long Plot, Silky Land, Miller Ground and Red Plot. )

He decides what type of work must be done urgently in the vineyards - one work for one day. (Works may be as follows:  Incision, spraying, spring opening and hoe work).
For example: "Silky Land, hoe work".  He sends his decision to the central vineyards office using pipe. 

Getting the decision the "Fine Wine Good Health" vineyards leader, the boss (parent process) gives the command to start the workers flight (second child process) to collect  
the workers for the daily task (e.g. Silky Land, hoe work). The leader sends  to the leader of the workers flight (the second child) the names of registered workers and 
the decision where to go and what to do ( use a  pipe). Reading the information the leader of the workers flight writes it out on the screen.

If there is not enough registered workers (less than the limit), the leader of the workers flight randomly select workers from the morning on the 
plot candidates. (Some workers may go without registration to the vineyards central office  - hoping that maybe there will be some working possibilities...) 
After arriving to the plot (e.g. to  Silky Land) the leader of the workers flight will send a signal to the central office (parent) how many workers were delivered. 
The office also writes out this data (the number) on the screen.
