// command.rs := Command-line Terminal
//

use super::supervisor::IDispatch;
use super::supervisor::IObserver;

trait IComponentCommand<T>
{
  fn execute(self) -> Result<T, std::boxed::Box<Self>>;
}

// Rust Compiler can derive the Copy, Clone traits from CompositeCommand...
#[derive(Copy, Clone)]
struct CompositeCommand;

// ... into InputHandler [Copy, Clone traits]
#[derive(Copy, Clone)]
struct InputHandler
{
  observe_command : CompositeCommand,
  dispose_command : CompositeCommand
}

impl IComponentCommand<CompositeCommand> for InputHandler
{
  fn execute(self) -> Result<CompositeCommand, std::boxed::Box<Self>>
  {
    let disposable = Option::None::<usize>;
    if let Some(leaf) = disposable
    {
      let observed = InputHandler::dispatch();
      let _ = InputHandler::use_effect(self, self.observe_command);

      return match InputHandler::handle(self)
      {
        | Ok(leaf) => InputHandler::use_effect(self, self.observe_command),
        | Err(_) => InputHandler::use_dispatch(self, self.dispose_command)
      };
    }
    else
    {
      let disposed : Result<CompositeCommand, Box<Self>> =
        InputHandler::dispatch();
      let _ = InputHandler::use_dispatch(self, self.dispose_command);

      return disposed;
    }
  }
}

impl From<CompositeCommand> for InputHandler
{
  fn from(value : CompositeCommand) -> Self
  {
    todo!()
  }
}

impl From<InputHandler> for CompositeCommand
{
  fn from(value : InputHandler) -> Self
  {
    todo!()
  }
}

impl InputHandler
{
  pub fn handle(self) -> Result<CompositeCommand, std::boxed::Box<Self>>
  {
    return Ok(self.observe_command);
  }

  pub fn use_effect(self,
                    observed : CompositeCommand)
                    -> Result<CompositeCommand, std::boxed::Box<Self>>
  {
    let leaf = match observed
    {
      | observed => Ok(CompositeCommand {})
    };

    return leaf;
  }

  pub fn use_dispatch(self,
                      disposed : CompositeCommand)
                      -> Result<CompositeCommand, std::boxed::Box<Self>>
  {
    let leaf = match disposed
    {
      | disposed => Ok(self.dispose_command)
    };

    return leaf;
  }
}

impl IObserver<CompositeCommand> for InputHandler
{
  fn observe() -> CompositeCommand
  {
    return CompositeCommand;
  }
}

impl IDispatch<CompositeCommand> for InputHandler
{
  fn dispatch() -> Result<CompositeCommand, Box<Self>>
  {
    let disposable = Option::None::<usize>;
    let leaf = match disposable
    {
      | _ => Ok(CompositeCommand)
    };

    return leaf;
  }
}
