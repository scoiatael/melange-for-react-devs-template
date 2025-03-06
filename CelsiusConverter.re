let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newCelsius = React.Event.Form.target(evt)##value;
        setCelsius(_ => newCelsius);
      }}
    />
    {React.string({js|°C = |js})}
    {React.string({js|?°F|js})}
  </div>;
};
