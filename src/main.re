type competitor = string;
type timestamp = int;
type durationUnit = Hours | Days | Months | Years;
type period = (int, durationUnit);


type standings = {
    winner: competitor,
    loser: competitor,
}

type matchParameters = {
    date: timestamp,
    timeout: period
};

type participants = (competitor, competitor);

type result =
    | Complete(standings)
    | TimedOut;

type match =
    | NotStarted(matchParameters, participants) 
    | InProgress(matchParameters, participants)
    | Complete(result);


let params = { date: 1, timeout: (5, Days) };
let ryan = "Ryan";
let tim = "Tim";
let newMatch = NotStarted(params, (ryan, tim));