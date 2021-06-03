struct ComputeInputs {
  [[builtin(local_invocation_id)]] local_invocation_id : vec3<u32>;
  [[builtin(local_invocation_index)]] local_invocation_index : u32;
  [[builtin(global_invocation_id)]] global_invocation_id : vec3<u32>;
  [[builtin(workgroup_id)]] workgroup_id : vec3<u32>;
  // TODO(crbug.com/tint/752): [[builtin(num_workgroups)]] num_workgroups : vec3<u32>;
};

[[stage(compute)]]
fn main(inputs : ComputeInputs) {
  let foo : u32 =
    inputs.local_invocation_id.x +
    inputs.local_invocation_index + 
    inputs.global_invocation_id.x + 
    inputs.workgroup_id.x;
}
