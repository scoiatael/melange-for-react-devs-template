let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;
let convertStr = celsius =>
  celsius |> float_of_string |> convert |> string_of_float;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");
  let (error, setError) = React.useState(() => "");
  let (fahrenheit, setFahrenheit) = React.useState(() => "?");

  <div>
    <input
      value=celsius
      id="celsius"
      onChange={evt => {
        let newCelsius = React.Event.Form.target(evt)##value;
        setCelsius(_ => newCelsius);
        switch (convertStr(newCelsius)) {
        | exception _ =>
          setError(_ => "couldn't convert");
          setFahrenheit(_ => "?");
        | value =>
          setFahrenheit(_ => value);
          setError(_ => "");
        };
      }}
    />
    {React.string({js|°C = |js})}
    {React.string(fahrenheit ++ {js|°F|js})}
    <br />
    <label
      style={ReactDOM.Style.make(~color="red", ~fontSize="small", ())}
      htmlFor="celsius">
      {React.string(error)}
    </label>
  </div>;
};
