type competitor = string;
type timestamp = int;
type durationUnit = Hours | Days | Months | Years;
type period = (int, durationUnit);
let add = (date: timestamp, period: period) => date;


type standings = {
    winner: competitor,
    loser: competitor,
}

type ruleset = {
    date: timestamp,
    timeout: period
};

let endTime = (ruleset) => add(ruleset.date, ruleset.timeout)

type participants = (competitor, competitor);

type result =
    | Reported(standings)
    | TimedOut;

type unscheduledState = {
    ruleset: ruleset,
    participants: participants
}

type scheduledState = {
    ruleset: ruleset,
    participants: participants,
    date: timestamp
}

type completedState = {
    ruleset: ruleset,
    result: result,
    date: timestamp
}


type match =
    | NotStarted(unscheduledState) 
    | InProgress(scheduledState)
    | Complete(completedState);

let scheduleMatch = (match: unscheduledState, date) => { ruleset: match.ruleset, participants: match.participants, date: date };
let reportMatch = (match: scheduledState, date, standings) => Complete({ ruleset: match.ruleset, date: date, result: Reported(standings)})
let markTimedOut = (match: scheduledState) => Complete({ ruleset: match.ruleset, date: endTime(match.ruleset), result: TimedOut})

