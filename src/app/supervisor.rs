// supervisor.rs := Observer design pattern
//

enum WorkStates
{
  Unassign,
  Assign,
  Kill
}

pub trait IObserver<T>
{
  fn observe() -> T;
}

pub trait IDispatch<T>
{
  fn dispatch() -> Result<T, std::boxed::Box<Self>>;
}

struct Supervisor;

impl Supervisor
{
}

struct Exercise {}

struct Worker
{
  supervisor : Supervisor,
  exercise : Exercise,
  state : WorkStates
}
